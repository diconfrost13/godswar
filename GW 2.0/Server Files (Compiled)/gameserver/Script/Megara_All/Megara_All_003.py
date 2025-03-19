import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1085 , Script.Quest.QI1089 , Script.Quest.QI1113 , Script.Quest.QI1162 , Script.Quest.QI1163 , Script.Quest.QI1170

def GetQuestReward():
  return Script.Quest.QR1084 , Script.Quest.QR1088 , Script.Quest.QR1162 , Script.Quest.QR1163 , Script.Quest.QR1170


def Talk( player ):
# print "talk to Megara_All_003"
  return "Megara_All_003"

