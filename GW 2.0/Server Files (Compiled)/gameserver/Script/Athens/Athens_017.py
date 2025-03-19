import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1135 , Script.Quest.QI1137 , Script.Quest.QI1138 , Script.Quest.QI1139

def GetQuestReward():
  return Script.Quest.QR1137 , Script.Quest.QR1138


def Talk( player ):
# print "talk to Athens_017"
  return "Athens_017"

