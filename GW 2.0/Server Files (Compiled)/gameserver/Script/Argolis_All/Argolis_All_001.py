import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI82 , Script.Quest.QI161 , Script.Quest.QI164

def GetQuestReward():
  return Script.Quest.QR81 , Script.Quest.QR161 , Script.Quest.QR164


def Talk( player ):
# print "talk to Argolis_All_001"
  return "Argolis_All_001"

