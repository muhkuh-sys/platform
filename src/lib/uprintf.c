/***************************************************************************
 *   Copyright (C) 2012 by Christoph Thelen                                *
 *   doc_bacardi@users.sourceforge.net                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "uprintf.h"

#include <stddef.h>
#include <string.h>

#include "serial_vectors.h"

/* This is the list of available line feed modes. */
#define CONSOLE_LINEFEED_LF    0  /* for Unix, Linux, Amiga, BeOS and MacOS X */
#define CONSOLE_LINEFEED_CR    1  /* for Apple II, old MacOS, OS-9 and C64 */
#define CONSOLE_LINEFEED_CRLF  2  /* for DOS, Windows, CP/M, OS/2, and Symbian */

/* Select one of the available line feed modes here. */
#define CONSOLE_LINEFEED CONSOLE_LINEFEED_CRLF


struct UPRINTF_OUTPUT_STRUCT;

typedef void (*PFN_UPRINTF_PUT_T) (struct UPRINTF_OUTPUT_STRUCT *ptV, char cOutput);
typedef void (*PFN_UPRINTF_FLUSH_T) (struct UPRINTF_OUTPUT_STRUCT *ptV);

typedef struct UPRINTF_OUTPUT_STRUCT
{
	PFN_UPRINTF_PUT_T fnPut;
	PFN_UPRINTF_FLUSH_T fnFlush;

	char *pcBufferStart;
	char *pcBufferCnt;
	char *pcBufferEnd;
	unsigned int uiCharsPrinted;
} UPRINTF_OUTPUT_T;



static void uprintf_hex(UPRINTF_OUTPUT_T *ptV, unsigned long ulValue, size_t sizMinimum, char cFillUpChar)
{
	int fLeadingDigitWasPrinted;
	size_t sizCnt;
	unsigned int uiDigit;


	/* the maximum size is 8 chars */
	sizCnt = 8;

	/* no leading digit was printed yet */
	fLeadingDigitWasPrinted = 0;

	/* loop over all possible chars */
	do
	{
		--sizCnt;

		/* get top digit */
		uiDigit = ulValue >> 28;
		if( uiDigit==0 && fLeadingDigitWasPrinted==0 && sizCnt>0 )
		{
			/* already reached the minimum display size? */
			if( sizCnt<sizMinimum )
			{
				/* yes -> print fillup char */
				ptV->fnPut(ptV, cFillUpChar);
			}
		}
		else
		{
			/* print the digit */
			uiDigit |= '0';
			if( uiDigit>'9' )
			{
				uiDigit += 'a'-'9'-1;
			}
			ptV->fnPut(ptV, (char)uiDigit);

			/* now the leading digit has been printed */
			fLeadingDigitWasPrinted = 1;
		}

		/* move to next digit */
		ulValue <<= 4;
	} while( sizCnt>0 );
}


static const unsigned long aulUprintfDecTab[10] =
{
	         1,
	        10,
	       100,
	      1000,
	     10000,
	    100000,
	   1000000,
	  10000000,
	 100000000,
	1000000000
};

static void uprintf_dec(UPRINTF_OUTPUT_T *ptV, unsigned long ulValue, size_t sizMinimum, char cFillUpChar)
{
	int fLeadingDigitWasPrinted;
	size_t sizCnt;
	unsigned int uiDigit;


	/* the maximum size is 10 chars */
	sizCnt = 10;

	/* no leading digit was printed yet */
	fLeadingDigitWasPrinted = 0;

	/* loop over all possible chars */
	do
	{
		--sizCnt;

		/* get top digit */
		uiDigit = 0;
		while( ulValue>=aulUprintfDecTab[sizCnt] )
		{
			ulValue -= aulUprintfDecTab[sizCnt];
			++uiDigit;
		}

		if( uiDigit==0 && fLeadingDigitWasPrinted==0 && sizCnt>0 )
		{
			/* already reached the minimum display size? */
			if( sizCnt<sizMinimum )
			{
				/* yes -> print fillup char */
				ptV->fnPut(ptV, cFillUpChar);
			}
		}
		else
		{
			/* print the digit */
			uiDigit |= '0';
			ptV->fnPut(ptV, (char)uiDigit);

			/* now the leading digit has been printed */
			fLeadingDigitWasPrinted = 1;
		}
	} while( sizCnt>0 );
}


static void uprintf_bin(UPRINTF_OUTPUT_T *ptV, unsigned long ulValue, size_t sizMinimum, char cFillUpChar)
{
	int fLeadingDigitWasPrinted;
	size_t sizCnt;
	unsigned int uiDigit;


	/* the maximum size is 32 chars */
	sizCnt = 32;

	/* no leading digit was printed yet */
	fLeadingDigitWasPrinted = 0;

	/* loop over all possible chars */
	do
	{
		--sizCnt;

		/* get top digit */
		uiDigit = ulValue >> 31;
		if( uiDigit==0 && fLeadingDigitWasPrinted==0 && sizCnt>0 )
		{
			/* already reached the minimum display size? */
			if( sizCnt<sizMinimum )
			{
				/* yes -> print fillup char */
				ptV->fnPut(ptV, cFillUpChar);
			}
		}
		else
		{
			/* print the digit */
			uiDigit |= '0';
			ptV->fnPut(ptV, (char)uiDigit);

			/* now the leading digit has been printed */
			fLeadingDigitWasPrinted = 1;
		}

		/* move to next digit */
		ulValue <<= 1;
	} while( sizCnt>0 );
}


static void uprintf_str(UPRINTF_OUTPUT_T *ptV, const char *pcString, size_t sizMinimum, char cFillUpChar)
{
	size_t sizString;
	size_t sizCnt;
	const char *pcCnt;
	char cChar;


	/* get the length of the string */
	sizString = 0;
	pcCnt = pcString;
	while( *(pcCnt++)!='\0' )
	{
		++sizString;
	}

	/* fillup string if it is smaller than the requested size */
	sizCnt = sizString;
	while( sizCnt<sizMinimum )
	{
		ptV->fnPut(ptV, cFillUpChar);
		++sizCnt;
	}

	/* print the string */
	pcCnt = pcString;
	do
	{
		cChar = *(pcCnt++);
		if( cChar!='\0' )
		{
			ptV->fnPut(ptV, cChar);
		}
	} while( cChar!='\0' );
}


static void uvprintf(const char *pcFmt, UPRINTF_OUTPUT_T *ptV, va_list ptArgs)
{
	char cChar;
	char cFillUpChar;
	size_t sizMinimumSize;
	int iDigitCnt;
	unsigned int uiCnt;
	unsigned int uiValue;
	const char *pcNumCnt;
	const char *pcNumEnd;
	unsigned long ulArgument;
	const char *pcArgument;
	int iArgument;


	/* Is the format string a NULL Pointer ? */
	if( pcFmt==NULL )
	{
		/* Replace the argument with the default string. */
		pcFmt = "NULL\n";
	}

	/* Loop over all chars in the format string. */
	do
	{
		/* Get the next char. */
		cChar = *(pcFmt++);

		/* Is this the end of the format string? */
		if( cChar!=0 )
		{
			/* No -> process the char. */

			/* Is this an escape char? */
			if( cChar=='%' )
			{
				/* Yes -> process the escape sequence. */

				/* Set default values for escape sequences. */
				cFillUpChar = ' ';
				sizMinimumSize = 0;

				do
				{
					cChar = *(pcFmt++);
					if( cChar=='%' )
					{
						/* It is just a '%'. */
						ptV->fnPut(ptV, cChar);
						break;
					}
					else if( cChar=='0' )
					{
						cFillUpChar = '0';
					}
					else if( cChar>'0' && cChar<='9' )
					{
						/* No digit found yet. */
						iDigitCnt = 1;
						/* The number started one char before. */
						pcNumEnd = pcFmt;
						/* Count all digits. */
						do
						{
							cChar = *pcFmt;
							if( cChar>='0' && cChar<='9' )
							{
								++pcFmt;
							}
							else
							{
								break;
							}
						} while(1);

						/* Loop over all digits and add them to the value. */
						uiValue = 0;
						iDigitCnt = 0;
						pcNumCnt = pcFmt;
						while( pcNumCnt>=pcNumEnd )
						{
							--pcNumCnt;
							uiCnt = (*pcNumCnt) & 0x0fU;
							while( uiCnt>0 )
							{
								uiValue += aulUprintfDecTab[iDigitCnt];
								--uiCnt;
							}
							++iDigitCnt;
						}
						sizMinimumSize = (size_t)uiValue;
					}
					else if( cChar=='x' )
					{
						/* Show a hexadecimal number. */
						ulArgument = va_arg((ptArgs), unsigned long);
						uprintf_hex(ptV, ulArgument, sizMinimumSize, cFillUpChar);
						break;
					}
					else if( cChar=='d' || cChar=='u' )
					{
						/* Show a decimal number. */
						ulArgument = va_arg((ptArgs), unsigned long);
						uprintf_dec(ptV, ulArgument, sizMinimumSize, cFillUpChar);
						break;
					}
					else if( cChar=='b' )
					{
						/* Show a binary number. */
						ulArgument = va_arg((ptArgs), unsigned long);
						uprintf_bin(ptV, ulArgument, sizMinimumSize, cFillUpChar);
						break;
					}
					else if( cChar=='s' )
					{
						/* Show a string. */
						pcArgument = va_arg((ptArgs), const char *);
						uprintf_str(ptV, pcArgument, sizMinimumSize, cFillUpChar);
						break;
					}
					else if( cChar=='c' )
					{
						/* Show a char. */
						iArgument = va_arg((ptArgs), int);
						ptV->fnPut(ptV, (char)iArgument);
						break;
					}
					else
					{
						ptV->fnPut(ptV, '*');
						ptV->fnPut(ptV, '*');
						ptV->fnPut(ptV, '*');
						break;
					}
				} while( cChar!=0 );
			}
			else if( cChar=='\n' )
			{
				/* Print line feed. */
#if CONSOLE_LINEFEED==CONSOLE_LINEFEED_LF
				/* Nothing to do for LF line feed. */
#elif CONSOLE_LINEFEED==CONSOLE_LINEFEED_CR
				cChar = '\r';
#elif CONSOLE_LINEFEED==CONSOLE_LINEFEED_CRLF
				ptV->fnPut(ptV, '\r');
#else
#       error "Invalid line feed mode!"
#endif
				ptV->fnPut(ptV, cChar);
				ptV->fnFlush(ptV);
			}
			else
			{
				ptV->fnPut(ptV, cChar);
			}
		}
	} while( cChar!=0 );
}



static void uprintf_serial_put(UPRINTF_OUTPUT_T *ptV, char cOutput)
{
	++ptV->uiCharsPrinted;
	tSerialVectors.fn.fnPut(cOutput);
}



static void uprintf_serial_flush(UPRINTF_OUTPUT_T *ptV __attribute__((unused)))
{
	tSerialVectors.fn.fnFlush();
}



void uprintf(const char *pcFmt, ...)
{
	va_list ptArgs;
	UPRINTF_OUTPUT_T tOut;


	if( (tSerialVectors.fn.fnPut!=NULL) && (tSerialVectors.fn.fnFlush!=NULL)  )
	{
		tOut.fnPut = uprintf_serial_put;
		tOut.fnFlush = uprintf_serial_flush;
		tOut.pcBufferStart = NULL;
		tOut.pcBufferCnt = NULL;
		tOut.pcBufferEnd = NULL;
		tOut.uiCharsPrinted = 0;

		va_start(ptArgs, pcFmt);
		uvprintf(pcFmt, &tOut, ptArgs);
		va_end(ptArgs);
	}
}



static void uprintf_buffer_put(UPRINTF_OUTPUT_T *ptV, char cOutput)
{
	/* Count all chars even if they do not fit into the buffer. */
	++ptV->uiCharsPrinted;

	/* Is space left in the buffer? */
	if( ptV->pcBufferCnt < ptV->pcBufferEnd )
	{
		/* Yes -> put the char in the buffer and increment the counter. */
		*(ptV->pcBufferCnt++) = cOutput;
	}
}



static void uprintf_buffer_flush(UPRINTF_OUTPUT_T *ptV __attribute((unused)))
{
	/* Nothing to do here. */
}



unsigned int usnprintf(char *pcBuffer, unsigned int sizBuffer, const char *pcFmt, ...)
{
	va_list ptArgs;
	UPRINTF_OUTPUT_T tOut;


	/* Sanitize the parameters. */
	if( pcBuffer==NULL )
	{
		sizBuffer = 0;
	}

	tOut.fnPut = uprintf_buffer_put;
	tOut.fnFlush = uprintf_buffer_flush;
	tOut.pcBufferStart = pcBuffer;
	tOut.pcBufferCnt = pcBuffer;
	tOut.pcBufferEnd = pcBuffer + sizBuffer;
	tOut.uiCharsPrinted = 0;

	va_start(ptArgs, pcFmt);
	uvprintf(pcFmt, &tOut, ptArgs);
	va_end(ptArgs);

	/* Add a 0 at the end of the buffer - if there is a buffer. */
	if( sizBuffer!=0 )
	{
		/* Is space left in the buffer? */
		if( tOut.pcBufferCnt<tOut.pcBufferEnd )
		{
			/* Yes -> append a 0. */
			*(tOut.pcBufferCnt) = '\0';
		}
		else
		{
			/* No space left -> overwrite the last char with a 0. */
			*(tOut.pcBufferCnt - 1) = '\0';
		}
	}

	return tOut.uiCharsPrinted;
}



void hexdump(const unsigned char *pcData, size_t sizData)
{
	const unsigned char *pcDumpCnt;
	const unsigned char *pcDumpEnd;
	unsigned long ulAddressCnt;
	size_t sizChunkCnt;
	size_t sizChunkSize;
	size_t sizBytesLeft;


	/* show a hexdump of the data */
	pcDumpCnt = pcData;
	pcDumpEnd = pcData + sizData;
	ulAddressCnt = 0;
	while( pcDumpCnt<pcDumpEnd )
	{
		/* get number of bytes for the next line */
		sizChunkSize = 16;
		/* trust me, it *is* positive */
		sizBytesLeft = (size_t)(pcDumpEnd-pcDumpCnt);
		if( sizChunkSize>sizBytesLeft )
		{
			sizChunkSize = sizBytesLeft;
		}

		/* start a line in the dump with the address */
		uprintf("%08x: ", ulAddressCnt);
		/* append the data bytes */
		sizChunkCnt = sizChunkSize;
		while( sizChunkCnt!=0 )
		{
			uprintf("%02x ", *pcDumpCnt);
			++pcDumpCnt;
			--sizChunkCnt;
		}
		ulAddressCnt += sizChunkSize;
		uprintf("\n");
	}
}

