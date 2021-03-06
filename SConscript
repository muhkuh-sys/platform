# -*- coding: utf-8 -*-

#----------------------------------------------------------------------------
# This is the list of sources. The elements must be separated with whitespace
# (i.e. spaces, tabs, newlines). The amount of whitespace does not matter.
sources = """
	src/lib/rdy_run.c
	src/lib/systime.c
	src/lib/uart.c
	src/lib/uart_standalone.c
	src/lib/uprintf.c
"""

sources_netx6 = """
	src/netx6/netx6_io_areas.c
"""

sources_netx4000 = """
	src/lib/rap_uart.c
"""

#----------------------------------------------------------------------------
#
# Build the library for all available environments.
#
Import('atEnv')

if hasattr(atEnv, 'NETX4000_RELAXED') == True:
	tEnvDefault = atEnv.NETX4000_RELAXED
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc = tEnv.SetBuildPath('targets/netx4000_relaxed', 'src', sources + sources_netx4000)
	tLib = tEnv.StaticLibrary('targets/platform_netx4000_relaxed', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETX4000') == True:
	tEnvDefault = atEnv.NETX4000
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc = tEnv.SetBuildPath('targets/netx4000', 'src', sources + sources_netx4000)
	tLib = tEnv.StaticLibrary('targets/platform_netx4000', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETX500') == True:
	tEnvDefault = atEnv.NETX500
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc = tEnv.SetBuildPath('targets/netx500', 'src', sources)
	tLib = tEnv.StaticLibrary('targets/platform_netx500', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETX90_MPW') == True:
	tEnvDefault = atEnv.NETX90_MPW
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc = tEnv.SetBuildPath('targets/netx90_mpw_com', 'src', sources)
	tLib = tEnv.StaticLibrary('targets/platform_netx90_mpw_com', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETX90_MPW_APP') == True:
	tEnvDefault = atEnv.NETX90_MPW_APP
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc = tEnv.SetBuildPath('targets/netx90_mpw_app', 'src', sources)
	tLib = tEnv.StaticLibrary('targets/platform_netx90_mpw_app', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETX90') == True:
	tEnvDefault = atEnv.NETX90
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc = tEnv.SetBuildPath('targets/netx90_com', 'src', sources)
	tLib = tEnv.StaticLibrary('targets/platform_netx90_com', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETX90_APP') == True:
	tEnvDefault = atEnv.NETX90_APP
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc = tEnv.SetBuildPath('targets/netx90_app', 'src', sources)
	tLib = tEnv.StaticLibrary('targets/platform_netx90_app', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETX56') == True:
	tEnvDefault = atEnv.NETX56
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc  = tEnv.SetBuildPath('targets/netx56', 'src', sources)
	tLib  = tEnv.StaticLibrary('targets/platform_netx56', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETX50') == True:
	tEnvDefault = atEnv.NETX50
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc  = tEnv.SetBuildPath('targets/netx50', 'src', sources)
	tLib  = tEnv.StaticLibrary('targets/platform_netx50', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETX10') == True:
	tEnvDefault = atEnv.NETX10
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc  = tEnv.SetBuildPath('targets/netx10', 'src', sources)
	tLib  = tEnv.StaticLibrary('targets/platform_netx10', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETX6') == True:
	tEnvDefault = atEnv.NETX6
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc  = tEnv.SetBuildPath('targets/netx6', 'src', sources + sources_netx6)
	tLib  = tEnv.StaticLibrary('targets/platform_netx6', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)

if hasattr(atEnv, 'NETIOL') == True:
	tEnvDefault = atEnv.NETIOL
	tEnv = tEnvDefault.Clone()
	tEnv.Append(CPPPATH = ['src', 'src/lib'])
	tEnv.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	tSrc  = tEnv.SetBuildPath('targets/netiol', 'src', sources)
	tLib  = tEnv.StaticLibrary('targets/platform_netiol', tSrc)
	tEnvDefault.Replace(PLATFORM_LIBRARY = tLib)
