import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1092

def GetQuestReward():
  return Script.Quest.QR1091 , Script.Quest.QR1207 , Script.Quest.QR1208 , Script.Quest.QR1209


def Talk( player ):
# print "talk to Parnitha_1_015"
  return "Parnitha_1_015"

