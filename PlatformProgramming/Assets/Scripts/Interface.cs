using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//�������̽�
public interface IPassive
{
    void PassiveSkill();
}
public interface IActive
{
    void ActiveSkill();
}
//�߻�Ŭ����
public abstract class Skill
{
    private int data;
    protected int data2;
    virtual public void passiveSkill()
    {

    }
    abstract public void activeSkill();
}
//�߻�Ŭ������ �Ļ�Ŭ������ ��� �߻�޼��带 �����ؾ��Ѵ�.
public class ActiveSkillType : Skill
{
    //passiveSkill() ������
    public override void passiveSkill()
    {
        base.passiveSkill();
    }
    //activeSkill() ����
    public override void activeSkill()
    {
        throw new System.NotImplementedException();
    }
}
public class PassiveSkillType : Skill
{
    //passiveSkill() ������
    public override void passiveSkill()
    {
        base.passiveSkill();
    }
    //activeSkill() ����
    public override void activeSkill()
    {
        throw new System.NotImplementedException();
    }
}
public class Interface : MonoBehaviour, IPassive, IActive
{
    void Start()
    {
        Skill skill1 = new ActiveSkillType();
        Skill skill2 = new PassiveSkillType();

        NpcTableParser.instance.LoadData("NpcData.csv");
        MonsterTableParser.instance.LoadData("MonsterData.csv");
    }
    public void PassiveSkill()
    {
        Debug.Log("PassiveSkill");
    }
    public void ActiveSkill()
    {
        Debug.Log("ActiveSkill");
    }
    void Update()
    {
        PassiveSkill();
        ActiveSkill();
    }
}
