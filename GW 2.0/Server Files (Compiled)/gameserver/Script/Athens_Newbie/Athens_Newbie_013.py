import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1104 , Script.Quest.QI1106 , Script.Quest.QI1184 , Script.Quest.QI1186 , Script.Quest.QI1187

def GetQuestReward():
  return Script.Quest.QR1104 , Script.Quest.QR1106 , Script.Quest.QR1183 , Script.Quest.QR1186 , Script.Quest.QR1187


def Talk( player ):
# print "talk to Athens_Newbie_013"
  return "Athens_Newbie_013"

