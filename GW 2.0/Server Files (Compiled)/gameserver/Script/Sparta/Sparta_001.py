import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI15 , Script.Quest.QI97 , Script.Quest.QI148 , Script.Quest.QI149

def GetQuestReward():
  return Script.Quest.QR14 , Script.Quest.QR96 , Script.Quest.QR148 , Script.Quest.QR149


def Talk( player ):
# print "talk to Sparta_001"
  return "Sparta_001"

