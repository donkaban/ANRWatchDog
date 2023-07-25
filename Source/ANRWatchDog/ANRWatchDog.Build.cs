using UnrealBuildTool;

public class ANRWatchDog : ModuleRules
{
	public ANRWatchDog(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
        PublicDependencyModuleNames.AddRange(new string[]
        {
	        "Core", 
	        "CoreUObject", 
	        "Engine"
        });

        string PluginPath = Utils.MakePathRelativeTo(ModuleDirectory, Target.RelativeEnginePath);
        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDependencyModuleNames.Add("Launch");
            AdditionalPropertiesForReceipt.Add("AndroidPlugin", System.IO.Path.Combine(PluginPath, "ANRWatchDogUPL.xml"));
        }
    }
}
