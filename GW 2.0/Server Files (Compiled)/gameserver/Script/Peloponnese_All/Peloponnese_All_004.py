import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI51 , Script.Quest.QI52 , Script.Quest.QI56 , Script.Quest.QI54 , Script.Quest.QI218

def GetQuestReward():
  return Script.Quest.QR50 , Script.Quest.QR51 , Script.Quest.QR55 , Script.Quest.QR53


def Talk( player ):
# print "talk to Peloponnese_All_004"
  return "Peloponnese_All_004"

