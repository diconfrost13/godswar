import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1007 , Script.Quest.QI1012 , Script.Quest.QI1145 , Script.Quest.QI1146 , Script.Quest.QI1147

def GetQuestReward():
  return Script.Quest.QR1006 , Script.Quest.QR1011 , Script.Quest.QR1145 , Script.Quest.QR1146 , Script.Quest.QR1147


def Talk( player ):
# print "talk to Athens_Newbie_005"
  return "Athens_Newbie_005"

