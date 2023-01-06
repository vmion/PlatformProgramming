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
            //앞뒤 공백문자를 지워주는 함수 : Trim()
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
        //FileList.txt 파일의 내용과 비교 정리
        //필요한 경우가 있을 수 있음
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
        //FileList.txt 파일의 내용을 내려받음
        using (StreamReader sr = new StreamReader(Application.dataPath + "/" + _fileName))
        {            
            string patchfileName = string.Empty;            
            while((patchfileName = sr.ReadLine()) != null)
            {
                patchList.Add(patchfileName);
            }
            sr.Close();
        }
        //List에 저장된 파일 이름을 서버에서 전송 받음
        for(int i = 0; i < patchList.Count; i++)
        {
            string url = "file:///" + "Z:\\github\\PlatformProgramming\\GClass\\" + curVersion + "\\" + patchList[i];
            //using구문을 사용하지 않아도 되지만, 사용시 가비지콜렉터를 더 효율적으로 이용 가능
            //구문이 끝나면 바로 삭제됨
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
