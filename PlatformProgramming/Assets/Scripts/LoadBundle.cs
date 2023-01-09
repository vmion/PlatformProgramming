using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LoadBundle : MonoBehaviour
{
    List<GameObject> rcAssetList;  
    void Start()
    {
        rcAssetList = new List<GameObject>();
        //string fileName = Application.dataPath + "/AssetBundles/" + "patch_1_1.assetbundle";
        string fileName = Application.dataPath + "/DownLoad/" + "patch_1_1.assetbundle";
        //StartCoroutine(LoadAllAssetBundle(fileName));
        LoadAllAssetBundles(fileName);
        CreateGameObject("Capsule", null);
    }
    IEnumerator LoadAllAssetBundle(string _fileName)
    {
        var bundlefile = AssetBundle.LoadFromFile(_fileName);
        GameObject[] objs = bundlefile.LoadAllAssets<GameObject>();
        for(int i = 0; i < objs.Length; i++)
        {
            rcAssetList.Add(objs[i]);
            yield return null;
        }
        bundlefile.Unload(false);
        Resources.UnloadUnusedAssets();        
    }
    public void LoadAllAssetBundles(string _fileName)
    {
        var bundlefile = AssetBundle.LoadFromFile(_fileName);
        GameObject[] objs = bundlefile.LoadAllAssets<GameObject>();
        for (int i = 0; i < objs.Length; i++)
        {
            rcAssetList.Add(objs[i]);            
        }
        bundlefile.Unload(false);
        Resources.UnloadUnusedAssets();
    }
    public GameObject CreateGameObject(string _name, Transform _parent)
    {
        GameObject obj = rcAssetList.Find(o=>(o.name.Equals(_name)));
        GameObject createObj = GameObject.Instantiate<GameObject>(obj);
        createObj.transform.position = Vector3.zero;
        createObj.name = _name;
        if(_parent != null)
            createObj.transform.SetParent(_parent.gameObject.transform);
        return createObj;
    }
    void Update()
    {
        
    }
}
