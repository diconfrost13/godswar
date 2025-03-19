import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI179 , Script.Quest.QI180 , Script.Quest.QI183

def GetQuestReward():
  return Script.Quest.QR179 , Script.Quest.QR180 , Script.Quest.QR185


def Talk( player ):
# print "talk to Sparta_041"
  return "Sparta_041"

