using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Networking;
using System.IO;

public class PatchManager : MonoBehaviour
{
    string curVersion;    
    IEnumerator Start()
    {        
        yield return StartCoroutine(GetCurversion("curVersion.txt"));
        yield return StartCoroutine(PatchAssetFile("FileList.txt"));
        yield return StartCoroutine(PatchFile("FileList.txt"));
        //yield return StartCoroutine(CompareFile());
    }    
    IEnumerator GetCurversion(string _fileName)
    {
        //string folder = (_folder == string.Empty) ? _folder : _folder + "\\";
        string url = "file:///" + "Z:\\github\\PlatformProgramming\\GClass\\" + _fileName;
        UnityWebRequest www = new UnityWebRequest(url);
        www.downloadHandler = new DownloadHandlerBuffer();
        yield return www.SendWebRequest();
        if(www.isNetworkError || www.isHttpError)
        {
            Debug.Log(www.error);
        }
        else
        {
            curVersion = www.downloadHandler.text.Trim();
            //�յ� ���鹮�ڸ� �����ִ� �Լ� : Trim()
            Debug.Log(www.downloadHandler.text);
            byte[] results = www.downloadHandler.data;
            File.WriteAllBytes(Application.dataPath + "/" + _fileName, results);
        }
    }  
    IEnumerator PatchAssetFile(string _fileName)
    {
        string url = "file:///" + "Z:\\github\\PlatformProgramming\\GClass\\" + curVersion + "\\"+ _fileName;
        UnityWebRequest www = new UnityWebRequest(url);
        www.downloadHandler = new DownloadHandlerBuffer();
        yield return www.SendWebRequest();
        if (www.isNetworkError || www.isHttpError)
        {
            Debug.Log(www.error);
        }
        else
        {
            string data = www.downloadHandler.text.Trim();
            Debug.Log(data);
            byte[] results = www.downloadHandler.data;
            File.WriteAllBytes(Application.dataPath + "/" + _fileName, results);
        }
    }
    IEnumerator CompareFile()
    {
        //FileList.txt ������ ����� �� ����
        //�ʿ��� ��찡 ���� �� ����
        yield return null;
    }
    IEnumerator PatchFile(string _fileName)
    {
        if(!File.Exists(Application.dataPath + "\\" + _fileName))
        {
            Debug.LogError("Patchfile is not exist");
            yield break;
        }
        if(!Directory.Exists(Application.dataPath + "\\" + "DownLoad"))
        {
            Directory.CreateDirectory(Application.dataPath + "\\" + "DownLoad");
        }
        List<string> patchList = new List<string>();
        //FileList.txt ������ ������ ��������
        using (StreamReader sr = new StreamReader(Application.dataPath + "/" + _fileName))
        {            
            string patchfileName = string.Empty;            
            while((patchfileName = sr.ReadLine()) != null)
            {
                patchList.Add(patchfileName);
            }
            sr.Close();
        }
        //List�� ����� ���� �̸��� �������� ���� ����
        for(int i = 0; i < patchList.Count; i++)
        {
            string url = "file:///" + "Z:\\github\\PlatformProgramming\\GClass\\" + curVersion + "\\" + patchList[i];
            //using������ ������� �ʾƵ� ������, ���� �������ݷ��͸� �� ȿ�������� �̿� ����
            //������ ������ �ٷ� ������
            using (UnityWebRequest www = new UnityWebRequest(url))
            {
                www.downloadHandler = new DownloadHandlerBuffer();
                yield return www.SendWebRequest();
                if (www.isNetworkError || www.isHttpError)
                {
                    Debug.Log(www.error);
                }
                else
                {
                    string data = www.downloadHandler.text.Trim();
                    Debug.Log(data);
                    byte[] results = www.downloadHandler.data;
                    File.WriteAllBytes(Application.dataPath + "/DownLoad/" + patchList[i], results);
                }
            }
        }
        patchList.Clear();
    }
    void Update()
    {
        
    }
}
