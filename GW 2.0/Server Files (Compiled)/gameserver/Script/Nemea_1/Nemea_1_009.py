import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI92

def GetQuestReward():
  return Script.Quest.QR91 , Script.Quest.QR207 , Script.Quest.QR208 , Script.Quest.QR209


def Talk( player ):
# print "talk to Nemea_1_009"
  return "Nemea_1_009"

