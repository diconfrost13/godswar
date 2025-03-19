import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI18 , Script.Quest.QI20 , Script.Quest.QI21

def GetQuestReward():
  return Script.Quest.QR17 , Script.Quest.QR19 , Script.Quest.QR20


def Talk( player ):
# print "talk to Sparta_003"
  return "Sparta_003"

