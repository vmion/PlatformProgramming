using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//인터페이스
public interface IPassive
{
    void PassiveSkill();
}
public interface IActive
{
    void ActiveSkill();
}
//추상클래스
public abstract class Skill
{
    private int data;
    protected int data2;
    virtual public void passiveSkill()
    {

    }
    abstract public void activeSkill();
}
//추상클래스의 파생클래스는 모든 추상메서드를 구현해야한다.
public class ActiveSkillType : Skill
{
    //passiveSkill() 재정의
    public override void passiveSkill()
    {
        base.passiveSkill();
    }
    //activeSkill() 구현
    public override void activeSkill()
    {
        throw new System.NotImplementedException();
    }
}
public class PassiveSkillType : Skill
{
    //passiveSkill() 재정의
    public override void passiveSkill()
    {
        base.passiveSkill();
    }
    //activeSkill() 구현
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
