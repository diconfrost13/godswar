import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1141 , Script.Quest.QI1142 , Script.Quest.QI1143 , Script.Quest.QI1144

def GetQuestReward():
  return Script.Quest.QR1140 , Script.Quest.QR1141 , Script.Quest.QR1143 , Script.Quest.QR1144


def Talk( player ):
# print "talk to Athens_Newbie_012"
  return "Athens_Newbie_012"

