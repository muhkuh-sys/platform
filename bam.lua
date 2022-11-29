-- Provide Penlight as an upvalue to all functions.
local pl = require'pl.import_into'()

-- Create the Lpeg_Support class.
local class = pl.class
local BAM_Platform = class()


---intialize BAM platform
function BAM_Platform:_init(atEnv)

  -- CC flags for all platforms.
  self.astrCommonCCFlags = {
      '-ffunction-sections',
      '-fdata-sections'
    }

  -- Include paths for all platforms.
  self.astrCommonIncludePaths = {
    'src',
    'src/lib'
  }

  -- Sources for all platforms.
  self.astrCommonSources = {
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
  self.atBuild = {
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
end


---execute BAM platform - the run object function with a boolean return value is neccessary to execute the subBAM in mbs2!
function BAM_Platform:run()
  local bResult = true

  for _, tBuild in ipairs(self.atBuild) do
    -- Get the base environment.
    -- If the base environment is nil, the main project did not define the compiler environment.
    -- This means the main project does not want to build a platform library for this target.
    local tBaseEnv = tBuild.tEnv
    if tBaseEnv~=nil then
      -- Clone the base environment.
      local tEnv = tBaseEnv:Clone()

      -- Set common CC flags for the platform lib.
      tEnv:AddCCFlags(self.astrCommonCCFlags)
      -- Add special CC flags for the build.
      tEnv:AddCCFlags(tBuild.astrExtraCCFlags)

      -- Set common include paths for the platform lib.
      tEnv:AddInclude(self.astrCommonIncludePaths)
      -- Add special include paths for the build.
      tEnv:AddInclude(tBuild.astrExtraIncludePaths)

      -- Collect all sources.
      local astrSources = {}
      -- Add the common sources for all platforms.
      pl.tablex.insertvalues(astrSources, self.astrCommonSources)
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

      -- Set prefix string of static library
      tEnv:SetLibPrefix("")

      -- Build a library from all objects.
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

  return bResult
end


return BAM_Platform
