import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1069 , Script.Quest.QI1090 , Script.Quest.QI1099

def GetQuestReward():
  return Script.Quest.QR1068 , Script.Quest.QR1089 , Script.Quest.QR1098


def Talk( player ):
# print "talk to Parnitha_1_001"
  return "Parnitha_1_001"

