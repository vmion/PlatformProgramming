using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEditor;

public class AssetBundleBuild
{
    [MenuItem("AssetBundle/BuildBundle")]
    static public void BuildBundle()
    {
        BuildPipeline.BuildAssetBundles("Assets/AssetBundles", 
                                        BuildAssetBundleOptions.None, 
                                        BuildTarget.StandaloneWindows);
    }
}
