import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI74 , Script.Quest.QI75 , Script.Quest.QI76 , Script.Quest.QI79

def GetQuestReward():
  return Script.Quest.QR73 , Script.Quest.QR74 , Script.Quest.QR75 , Script.Quest.QR78


def Talk( player ):
# print "talk to Nemea_1_004"
  return "Nemea_1_004"

