import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI204 , Script.Quest.QI205 , Script.Quest.QI206

def GetQuestReward():
  return Script.Quest.QR150 , Script.Quest.QR204 , Script.Quest.QR205 , Script.Quest.QR206 , Script.Quest.QR223 , Script.Quest.QR224 , Script.Quest.QR225 , Script.Quest.QR226


def Talk( player ):
# print "talk to Argolis_All_006"
  return "Argolis_All_006"

