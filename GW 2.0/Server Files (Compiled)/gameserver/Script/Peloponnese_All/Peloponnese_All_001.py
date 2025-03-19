import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI49 , Script.Quest.QI57 , Script.Quest.QI59

def GetQuestReward():
  return Script.Quest.QR48 , Script.Quest.QR56 , Script.Quest.QR58


def Talk( player ):
# print "talk to Peloponnese_All_001"
  return "Peloponnese_All_001"

