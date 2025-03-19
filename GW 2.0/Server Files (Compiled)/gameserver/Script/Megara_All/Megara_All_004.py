import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1086 , Script.Quest.QI1087 , Script.Quest.QI1088 , Script.Quest.QI1165 , Script.Quest.QI1166 , Script.Quest.QI1169 , Script.Quest.QI1217

def GetQuestReward():
  return Script.Quest.QR1085 , Script.Quest.QR1086 , Script.Quest.QR1087 , Script.Quest.QR1165 , Script.Quest.QR1166 , Script.Quest.QR1169 , Script.Quest.QR1222


def Talk( player ):
# print "talk to Megara_All_004"
  return "Megara_All_004"

