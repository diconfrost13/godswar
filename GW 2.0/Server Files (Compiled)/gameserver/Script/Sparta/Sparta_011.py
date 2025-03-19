import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI43 , Script.Quest.QI136

def GetQuestReward():
  return Script.Quest.QR42 , Script.Quest.QR135 , Script.Quest.QR136


def Talk( player ):
# print "talk to Sparta_011"
  return "Sparta_011"

