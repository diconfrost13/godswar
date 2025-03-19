import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1062 , Script.Quest.QI1063 , Script.Quest.QI1066

def GetQuestReward():
  return Script.Quest.QR1061 , Script.Quest.QR1062 , Script.Quest.QR1065


def Talk( player ):
# print "talk to Marathon_All_005"
  return "Marathon_All_005"

