using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class NpcTableParser : ParserBase<NpcTableParser, NpcData>
{
    private static NpcTableParser Instance;
    public static NpcTableParser instance
    {
        get
        {
            if (null == Instance)
            {
                return null;
            }
            return Instance;
        }
    }    
    public override void ReadData(string[] _datas)
    {
        NpcData tmp;
        tmp.index = int.Parse(_datas[0]);
        tmp.name = _datas[1];
        tmp.jobType = byte.Parse(_datas[2]);
        base.AddData(tmp);
    }
}
