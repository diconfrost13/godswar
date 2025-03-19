import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI72 , Script.Quest.QI80 , Script.Quest.QI91

def GetQuestReward():
  return Script.Quest.QR71 , Script.Quest.QR79 , Script.Quest.QR90


def Talk( player ):
# print "talk to Nemea_1_003"
  return "Nemea_1_003"

