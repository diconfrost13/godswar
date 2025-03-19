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
class AltarApp_0(Approach):#第一个操作步骤
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def Callback(self,Index,player):
          Consortia =  GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_UNION)#获取玩家所在工会ID
          Job =  GameAPI.GetPlayerAttr(player,Script.SysFun.FIELD_UNIONBUSINESS)#获取玩家的工会职务
          if Consortia != 0 and Job >= 5:#判断玩家的操作权限
             return True,1,2,3,4,5,6 #会长和副会长返回全部操作
          elif Consortia != 0:
             return True,4,5,6 #普通会员返回个人供奉操作
          else:
             return True,1000 #沒加入工会返回提示1000

class AltarApp_1(Approach):#第二个操作步骤
    
      def __init__(self,ID):
          Approach.__init__(self,ID)
          
      def Callback(self,Oper,player):
          if Oper[0] != Script.NPCConfig.NPC_FLAG_SYS_ALTAR:#判断玩家的第一步操作是否合法
             return False,
          if Oper[1] == 1:#创建祭坛
             res=GameAPI.GetHaveAltars(player)#获取玩家所属工会已有的祭坛ID列表
             res.sort()#对列表排序
             maxsl=GameAPI.GetUnionMaxAltar(player)#获取玩家所属工会当前等级下能创建的祭坛最大数
             all=[]
             for a in Script.Altar.AllAltar:#得到所有祭坛的ID
                 all.append(a.GetID())
             CreateAltar = list(set(all).difference(res))#选出玩家所属工会现在没有创建过的祭坛
             if res.__len__() < maxsl:#判断玩家公会祭坛数是否打到最大
                 CreateAltar.insert(0,True)#把True插入到CreateAltar的第一个位置
                 return tuple(CreateAltar)#把CreateAltar的数据类型强制转换为元组并返回給客户端
             else:
                 return True,1001 #玩家工会祭坛数达到最大，返回提示1001
          elif Oper[1] == 2 or Oper[1] == 3:# 升级和删除祭坛
             res=GameAPI.GetHaveAltars(player)
             res.sort()
             if res.__len__() >0:#判断玩家所属工会是否创建过祭坛如果是返回祭坛列表，否则返回提示信息1002
                 res.insert(0,True)
                 return tuple(res)
             else:
                 return True,1002 
          elif Oper[1] == 4:#添加供奉
             res=GameAPI.GetHavePlayerAltar(player)#获取玩家自己已供奉的祭坛列表
             res.sort()
             unionall=GameAPI.GetHaveAltars(player)
             unionall.sort()
             CreateAltar = list(set(unionall).difference(res))#选出玩家还能供奉的祭坛列表
             if CreateAltar.__len__() > 0:#判断玩家能供奉的祭坛列表是否非空，是则返回祭坛列表，否则返回提示信息1003
                CreateAltar.insert(0,True) 
                return tuple(CreateAltar)
             else:
                return True,1003 
          elif Oper[1] == 5 or Oper[1] == 6:#升级和删除供奉
             res=GameAPI.GetHavePlayerAltar(player)
             res.sort()
             if res.__len__() >0 :#判断玩家是否提升过供奉如果是返回祭坛列表，否则返回提示信息1004
                 res.insert(0,True)
                 return tuple(res)
             else:
                 return True,1004 
          else:
             return False,
            
class AltarApp_2(Approach):#第三个操作步骤
      def __init__(self,ID):
          Approach.__init__(self,ID)
      def Callback(self,Oper,player):
          if Oper[0] != Script.NPCConfig.NPC_FLAG_SYS_ALTAR:#判断玩家前两次操作是否合法，不合法抛出异常提示
             return True,1005
          if Oper[1] == -1 or Oper[1] > 6:
             return True,1005
          if Oper[2] == -1 or Oper[2] > 10:
             return True,1005
          if Oper[1] == 1 :   #添加祭坛,添加成功返回1006，失败返回1007
              if GameAPI.AltarCreate( player,Script.Altar.AllAltar[Oper[2]-1].GetID() ):
                  return True,1006
              else:
                  return True,1007 
          elif Oper[1] == 3:   #升级祭坛,升级成功返回1008，失败返回1009
              if GameAPI.AltarLevelup( player,Script.Altar.AllAltar[Oper[2]-1].GetID() ):
                  return True,1008
              else:
                  return True,1009
          elif Oper[1] == 2:    #删除祭坛,删除成功返回1010，失败返回1011
              if GameAPI.AltarDel( player,Script.Altar.AllAltar[Oper[2]-1].GetID() ):
                  return True,1010
              else:
                  return True,1011
          elif Oper[1] == 4:    #添加供奉,添加成功返回1012，失败返回1013
              if GameAPI.OblationLevelup( player,Script.Altar.AllAltar[Oper[2]-1].GetID(), Script.NPCConfig.TYPE_OBLATION_CREATE_LEVELUP ):
                  return True,1012
              else:
                  return True,1013
          elif Oper[1] == 5:    #删除供奉，删除成功返回1014，失败返回1015
              if GameAPI.OblationLevelup( player,Script.Altar.AllAltar[Oper[2]-1].GetID(), Script.NPCConfig.TYPE_OBLATION_DELETE  ):
                  return True,1014
              else:
                  return True,1015
          elif Oper[1] == 6:    #升级供奉，升级成功返回1016，失败返回1017
              if GameAPI.OblationLevelup( player,Script.Altar.AllAltar[Oper[2]-1].GetID(), Script.NPCConfig.TYPE_OBLATION_CREATE_LEVELUP ):
                  return True,1016
              else:
                  return True,1017
          else: 
              return True,1005 #玩家的操作非法，返回提示1005
              
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

