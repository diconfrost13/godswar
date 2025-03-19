import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1179 , Script.Quest.QI1180 , Script.Quest.QI1183

def GetQuestReward():
  return Script.Quest.QR1179 , Script.Quest.QR1180 , Script.Quest.QR1185


def Talk( player ):
# print "talk to Athens_040"
  return "Athens_040"

