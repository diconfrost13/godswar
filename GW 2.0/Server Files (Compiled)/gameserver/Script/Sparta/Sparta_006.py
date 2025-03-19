import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI28 , Script.Quest.QI30

def GetQuestReward():
  return Script.Quest.QR27 , Script.Quest.QR29


def Talk( player ):
# print "talk to Sparta_006"
  return "Sparta_006"

