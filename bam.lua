local pl = require'pl.import_into'()

-- CC flags for all platforms.
local astrCommonCCFlags = {
  '-ffunction-sections',
  '-fdata-sections'
}

-- Include paths for all platforms.
local astrCommonIncludePaths = {
  'src',
  'src/lib'
}

-- Sources for all platforms.
local astrCommonSources = {
  'src/lib/rdy_run.c',
  'src/lib/systime.c',
  'src/lib/uart.c',
  'src/lib/uart_standalone.c',
  'src/lib/uprintf.c'
}

-- Define a list of build targets with...
--  * id: name for the target folder and target library
--  * tEnv: the bvase environment defining the compiler
--  * astrExtraCCFlags: optional list of extra CC flags
--  * astrExtraIncludePaths: optional list of extra include paths
--  * astrExtraSources: optional list of extra sources
local atBuild = {
  {
    id = 'netx4000',
    tEnv = atEnv.NETX4000,
    astrExtraCCFlags = nil,
    astrExtraIncludePaths = nil,
    astrExtraSources = {
      'src/lib/rap_uart.c'
    }
  },
  {
    id = 'netx500',
    tEnv = atEnv.NETX500,
    astrExtraCCFlags = nil,
    astrExtraIncludePaths = nil,
    astrExtraSources = nil
  },
  {
    id = 'netx50',
    tEnv = atEnv.NETX50,
    astrExtraCCFlags = nil,
    astrExtraIncludePaths = nil,
    astrExtraSources = nil
  },
  {
    id = 'netx56',
    tEnv = atEnv.NETX56,
    astrExtraCCFlags = nil,
    astrExtraIncludePaths = nil,
    astrExtraSources = nil
  },
  {
    id = 'netx10',
    tEnv = atEnv.NETX10,
    astrExtraCCFlags = nil,
    astrExtraIncludePaths = nil,
    astrExtraSources = nil
  },
  {
    id = 'netx90',
    tEnv = atEnv.NETX90,
    astrExtraCCFlags = nil,
    astrExtraIncludePaths = nil,
    astrExtraSources = nil
  }
}
for _, tBuild in ipairs(atBuild) do
  -- Get the base environment.
  -- If the base environment is nil, the main project did not define the compiler environment.
  -- This means the main project does not want to build a platform library for this target.
  local tBaseEnv = tBuild.tEnv
  if tBaseEnv~=nil then
    -- Clone the base environment.
    local tEnv = tBaseEnv:Clone()

    -- Set common CC flags for the platform lib.
    tEnv:AddCCFlags(astrCommonCCFlags)
    -- Add special CC flags for the build.
    tEnv:AddCCFlags(tBuild.astrExtraCCFlags)

    -- Set common include paths for the platform lib.
    tEnv:AddInclude(astrCommonIncludePaths)
    -- Add special include paths for the build.
    tEnv:AddInclude(tBuild.astrExtraIncludePaths)

    -- Collect all sources.
    local astrSources = {}
    -- Add the common sources for all platforms.
    pl.tablex.insertvalues(astrSources, astrCommonSources)
    -- Add special sources for the build.
    if tBuild.astrExtraSources~=nil then
      pl.tablex.insertvalues(astrSources, tBuild.astrExtraSources)
    end

    -- Set ouput path for all sources.
    tEnv:SetBuildPath(
      'src/lib',
      pl.path.join('targets', tBuild.id, 'lib')
    )

    -- Build all sources.
    local atObjects = tEnv:Compile(astrSources)

    -- Build a library from all objects.
    -- TODO: The output name is generated somehow. Make this more intuitive. Or document how it works. :)
    local tPlatformLib = tEnv:StaticLibrary(
      pl.path.join(
        'targets',
        string.format('platform_%s', tBuild.id)
      ),
      atObjects
    )
    -- Add the platform lib to the environment variables.
    -- IMPORTANT: Add this to the base environment. The tEnv is only a local clone.
    tBaseEnv.atVars.PLATFORM_LIB = tPlatformLib
  end
end
