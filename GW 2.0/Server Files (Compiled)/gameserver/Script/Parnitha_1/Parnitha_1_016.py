import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1093 , Script.Quest.QI1094 , Script.Quest.QI1111 , Script.Quest.QI1112

def GetQuestReward():
  return Script.Quest.QR1092 , Script.Quest.QR1093 , Script.Quest.QR1111 , Script.Quest.QR1112


def Talk( player ):
# print "talk to Parnitha_1_016"
  return "Parnitha_1_016"

