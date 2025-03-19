import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI101 , Script.Quest.QI102 , Script.Quest.QI103

def GetQuestReward():
  return Script.Quest.QR101 , Script.Quest.QR102 , Script.Quest.QR103


def Talk( player ):
# print "talk to Sparta_019"
  return "Sparta_019"

