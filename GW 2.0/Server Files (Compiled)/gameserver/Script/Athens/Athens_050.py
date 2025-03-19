# -*- coding:UTF-8 -*- 
import Script.Global
import Script.Item
import Script.Altar
import GameAPI
import Script.SysFun
from  Script.SysFun import  Alter
from  Script.SysFun import  Tranmit
from  Script.SysFun import  Approach
from  Script.SysFun import  Exchange
from  Script.SysFun import  Offical
from  Script.SysFun import  Salary

##################################################
class AltarApp_0(Approach):#��һ����������
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def Callback(self,Index,player):
          Consortia =  GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_UNION)#��ȡ������ڹ���ID
          Job =  GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_UNIONBUSINESS)#��ȡ��ҵĹ���ְ��
          if Consortia != 0 and Job >= 5:#�ж���ҵĲ���Ȩ��
             return True,1,2,3,4,5,6 #�᳤�͸��᳤����ȫ������
          elif Consortia != 0:
             return True,4,5,6 #��ͨ��Ա���ظ��˹������
          else:
             return True,1000 #�]���빤�᷵����ʾ1000

class AltarApp_1(Approach):#�ڶ�����������
    
      def __init__(self,ID):
          Approach.__init__(self,ID)
          
      def Callback(self,Oper,player):
          if Oper[0] != Script.NPCConfig.NPC_FLAG_SYS_ALTAR:#�ж���ҵĵ�һ�������Ƿ�Ϸ�
             return False,
          if Oper[1] == 1:#������̳
             res=GameAPI.GetHaveAltars(player)#��ȡ��������������еļ�̳ID�б�
             res.sort()#���б�����
             maxsl=GameAPI.GetUnionMaxAltar(player)#��ȡ����������ᵱǰ�ȼ����ܴ����ļ�̳�����
             all=[]
             for a in Script.Altar.AllAltar:#�õ����м�̳��ID
                 all.append(a.GetID())
             CreateAltar = list(set(all).difference(res))#ѡ�����������������û�д������ļ�̳
             if res.__len__() < maxsl:#�ж���ҹ����̳���Ƿ�����
                 CreateAltar.insert(0,True)#��True���뵽CreateAltar�ĵ�һ��λ��
                 return tuple(CreateAltar)#��CreateAltar����������ǿ��ת��ΪԪ�鲢���ؽo�ͻ���
             else:
                 return True,1001 #��ҹ����̳���ﵽ��󣬷�����ʾ1001
          elif Oper[1] == 2 or Oper[1] == 3:# ������ɾ����̳
             res=GameAPI.GetHaveAltars(player)
             res.sort()
             if res.__len__() >0:#�ж�������������Ƿ񴴽�����̳����Ƿ��ؼ�̳�б����򷵻���ʾ��Ϣ1002
                 res.insert(0,True)
                 return tuple(res)
             else:
                 return True,1002 
          elif Oper[1] == 4:#��ӹ���
             res=GameAPI.GetHavePlayerAltar(player)#��ȡ����Լ��ѹ���ļ�̳�б�
             res.sort()
             unionall=GameAPI.GetHaveAltars(player)
             unionall.sort()
             CreateAltar = list(set(unionall).difference(res))#ѡ����һ��ܹ���ļ�̳�б�
             if CreateAltar.__len__() > 0:#�ж�����ܹ���ļ�̳�б��Ƿ�ǿգ����򷵻ؼ�̳�б����򷵻���ʾ��Ϣ1003
                CreateAltar.insert(0,True) 
                return tuple(CreateAltar)
             else:
                return True,1003 
          elif Oper[1] == 5 or Oper[1] == 6:#������ɾ������
             res=GameAPI.GetHavePlayerAltar(player)
             res.sort()
             if res.__len__() >0 :#�ж�����Ƿ���������������Ƿ��ؼ�̳�б����򷵻���ʾ��Ϣ1004
                 res.insert(0,True)
                 return tuple(res)
             else:
                 return True,1004 
          else:
             return False,
            
class AltarApp_2(Approach):#��������������
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def Callback(self,Oper,player):
          if Oper[0] != Script.NPCConfig.NPC_FLAG_SYS_ALTAR:#�ж����ǰ���β����Ƿ�Ϸ������Ϸ��׳��쳣��ʾ
             return True,1005
          if Oper[1] == -1 or Oper[1] > 6:
             return True,1005
          if Oper[2] == -1 or Oper[2] > 10:
             return True,1005
          if Oper[1] == 1 :   #��Ӽ�̳,��ӳɹ�����1006��ʧ�ܷ���1007
              if GameAPI.AltarCreate( player,Script.Altar.AllAltar[Oper[2]-1].GetID() ):
                  return True,1006
              else:
                  return True,1007 
          elif Oper[1] == 3:   #������̳,�����ɹ�����1008��ʧ�ܷ���1009
              if GameAPI.AltarLevelup( player,Script.Altar.AllAltar[Oper[2]-1].GetID() ):
                  return True,1008
              else:
                  return True,1009
          elif Oper[1] == 2:    #ɾ����̳,ɾ���ɹ�����1010��ʧ�ܷ���1011
              if GameAPI.AltarDel( player,Script.Altar.AllAltar[Oper[2]-1].GetID() ):
                  return True,1010
              else:
                  return True,1011
          elif Oper[1] == 4:    #��ӹ���,��ӳɹ�����1012��ʧ�ܷ���1013
              if GameAPI.OblationLevelup( player,Script.Altar.AllAltar[Oper[2]-1].GetID(), Script.NPCConfig.TYPE_OBLATION_CREATE_LEVELUP ):
                  return True,1012
              else:
                  return True,1013
          elif Oper[1] == 5:    #ɾ�����ɾ���ɹ�����1014��ʧ�ܷ���1015
              if GameAPI.OblationLevelup( player,Script.Altar.AllAltar[Oper[2]-1].GetID(), Script.NPCConfig.TYPE_OBLATION_DELETE  ):
                  return True,1014
              else:
                  return True,1015
          elif Oper[1] == 6:    #������������ɹ�����1016��ʧ�ܷ���1017
              if GameAPI.OblationLevelup( player,Script.Altar.AllAltar[Oper[2]-1].GetID(), Script.NPCConfig.TYPE_OBLATION_CREATE_LEVELUP ):
                  return True,1016
              else:
                  return True,1017
          else: 
              return True,1005 #��ҵĲ����Ƿ���������ʾ1005
              
AltarAppTuple = (AltarApp_0(0),AltarApp_1(1),AltarApp_2(2),None)
#######################################################

def test():
    pass

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_SYS)

def GetSysType():
  return  Script.NPCConfig.NPC_FLAG_SYS_ALTAR

def GetContentList():
  return {
          Script.NPCConfig.NPC_FLAG_SYS_ALTAR:AltarAppTuple
         }


def Talk( player ):
# print "talk to Athens_050"
  return "Athens_050"

