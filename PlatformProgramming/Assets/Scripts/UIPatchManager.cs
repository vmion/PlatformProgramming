using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class UIPatchManager : MonoBehaviour
{
    public PatchManager patchManager;
    public Text UIPatchFileName;
    public Text UIPatchFileCount;
    public Image UIPatchGauge;
    public Text UIMessage;
    int preCount;
    void Start()
    {
        
    }

    void Update()
    {
        UIPatchFileCount.text = patchManager.curCount.ToString() + "/" + patchManager.totalFileCount.ToString();
        UIPatchFileName.text = patchManager.curFileName;
        if(preCount != patchManager.curCount)
        {
            UIPatchGauge.fillAmount = (float)patchManager.curCount / (float)patchManager.totalFileCount;
        }
        
    }
}
