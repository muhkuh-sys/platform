# -*- coding: utf-8 -*-

Import('PLATFORM_LIB_CFG_BUILDS')


#----------------------------------------------------------------------------
# This is the list of sources. The elements must be separated with whitespace
# (i.e. spaces, tabs, newlines). The amount of whitespace does not matter.
sources = """
	src/lib/rdy_run.c
	src/lib/systime.c
	src/lib/uart.c
	src/lib/uprintf.c
"""

sources_netx6 = """
	src/netx6/netx6_io_areas.c
"""


#----------------------------------------------------------------------------
#
# Build the library for all targets.
#

if 500 in PLATFORM_LIB_CFG_BUILDS:
	Import('env_netx500_default')
	env_netx500 = env_netx500_default.Clone()
	env_netx500.Append(CPPPATH = ['src', 'src/lib'])
	env_netx500.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	src_netx500 = env_netx500.SetBuildPath('targets/netx500', 'src', sources)
	platform_lib_netx500 = env_netx500.StaticLibrary('targets/platform_netx500', src_netx500)
	Export('platform_lib_netx500')

if 56 in PLATFORM_LIB_CFG_BUILDS:
	Import('env_netx56_default')
	env_netx56  = env_netx56_default.Clone()
	env_netx56.Append(CPPPATH = ['src', 'src/lib'])
	env_netx56.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	src_netx56  = env_netx56.SetBuildPath('targets/netx56', 'src', sources)
	platform_lib_netx56  = env_netx56.StaticLibrary('targets/platform_netx56', src_netx56)
	Export('platform_lib_netx56')

if 50 in PLATFORM_LIB_CFG_BUILDS:
	Import('env_netx50_default')
	env_netx50  = env_netx50_default.Clone()
	env_netx50.Append(CPPPATH = ['src', 'src/lib'])
	env_netx50.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	src_netx50  = env_netx50.SetBuildPath('targets/netx50', 'src', sources)
	platform_lib_netx50  = env_netx50.StaticLibrary('targets/platform_netx50', src_netx50)
	Export('platform_lib_netx50')

if 10 in PLATFORM_LIB_CFG_BUILDS:
	Import('env_netx10_default')
	env_netx10  = env_netx10_default.Clone()
	env_netx10.Append(CPPPATH = ['src', 'src/lib'])
	env_netx10.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	src_netx10  = env_netx10.SetBuildPath('targets/netx10', 'src', sources)
	platform_lib_netx10  = env_netx10.StaticLibrary('targets/platform_netx10', src_netx10)
	Export('platform_lib_netx10')

if 6 in PLATFORM_LIB_CFG_BUILDS:
	Import('env_netx6_default')
	env_netx6  = env_netx6_default.Clone()
	env_netx6.Append(CPPPATH = ['src', 'src/lib'])
	env_netx6.Append(CCFLAGS = ['-ffunction-sections', '-fdata-sections'])
	src_netx6  = env_netx6.SetBuildPath('targets/netx6', 'src', sources + sources_netx6)
	platform_lib_netx6  = env_netx6.StaticLibrary('targets/platform_netx6', src_netx6)
	Export('platform_lib_netx6')

