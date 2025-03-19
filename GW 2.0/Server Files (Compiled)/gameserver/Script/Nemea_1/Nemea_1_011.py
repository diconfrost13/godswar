import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI95 , Script.Quest.QI96 , Script.Quest.QI98

def GetQuestReward():
  return Script.Quest.QR94 , Script.Quest.QR95 , Script.Quest.QR97


def Talk( player ):
# print "talk to Nemea_1_011"
  return "Nemea_1_011"

