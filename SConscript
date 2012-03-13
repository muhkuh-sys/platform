# -*- coding: utf-8 -*-

Import('env_default')

#----------------------------------------------------------------------------
# This is the list of sources. The elements must be separated with whitespace
# (i.e. spaces, tabs, newlines). The amount of whitespace does not matter.
sources = """
	src/lib/rdy_run.c
	src/lib/systime.c
	src/lib/uart.c
	src/lib/uprintf.c
"""


#----------------------------------------------------------------------------
#
# Create the default environment for all CPUs.
#

env_netx500_default = env_default.CreateCompilerEnv('500', ['cpu=arm926ej-s'])
env_netx500_default.Replace(BOOTBLOCK_CHIPTYPE = 500)
env_netx500_default.Append(CPPPATH = ['src', 'src/lib'])

env_netx56_default = env_default.CreateCompilerEnv('56', ['cpu=arm966e-s'])
env_netx56_default.Replace(BOOTBLOCK_CHIPTYPE = 56)
env_netx56_default.Append(CPPPATH = ['src', 'src/lib'])

env_netx50_default = env_default.CreateCompilerEnv('50', ['cpu=arm966e-s'])
env_netx50_default.Replace(BOOTBLOCK_CHIPTYPE = 50)
env_netx50_default.Append(CPPPATH = ['src', 'src/lib'])

env_netx10_default = env_default.CreateCompilerEnv('10', ['cpu=arm966e-s'])
env_netx10_default.Replace(BOOTBLOCK_CHIPTYPE = 10)
env_netx10_default.Append(CPPPATH = ['src', 'src/lib'])


#----------------------------------------------------------------------------
#
# Build the library for all targets.
#

env_netx500 = env_netx500_default.Clone()
src_netx500 = env_netx500.SetBuildPath('targets/netx500', 'src', sources)
platform_lib_netx500 = env_netx500.StaticLibrary('targets/platform_netx500', src_netx500)

env_netx56  = env_netx56_default.Clone()
src_netx56  = env_netx56.SetBuildPath('targets/netx56', 'src', sources)
platform_lib_netx56  = env_netx56.StaticLibrary('targets/platform_netx56', src_netx56)

env_netx50  = env_netx50_default.Clone()
src_netx50  = env_netx50.SetBuildPath('targets/netx50', 'src', sources)
platform_lib_netx50  = env_netx50.StaticLibrary('targets/platform_netx50', src_netx50)

env_netx10  = env_netx10_default.Clone()
src_netx10  = env_netx10.SetBuildPath('targets/netx10', 'src', sources)
platform_lib_netx10  = env_netx10.StaticLibrary('targets/platform_netx10', src_netx10)


Export('platform_lib_netx500', 'platform_lib_netx56', 'platform_lib_netx50', 'platform_lib_netx10')
