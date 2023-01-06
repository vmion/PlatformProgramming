using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class MonsterTableParser : ParserBase<NpcTableParser, MonsterData>
{
    private static MonsterTableParser Instance;
    public static MonsterTableParser instance
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
        MonsterData tmp;
        tmp.index = int.Parse(_datas[0]);
        tmp.name = _datas[1];
        tmp.jobType = byte.Parse(_datas[2]);
        base.AddData(tmp);
    }
}
