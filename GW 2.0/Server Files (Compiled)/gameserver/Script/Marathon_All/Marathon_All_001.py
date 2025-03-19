import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1049 , Script.Quest.QI1057 , Script.Quest.QI1059

def GetQuestReward():
  return Script.Quest.QR1048 , Script.Quest.QR1056 , Script.Quest.QR1058


def Talk( player ):
# print "talk to Marathon_All_001"
  return "Marathon_All_001"

