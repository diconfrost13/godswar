import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI104 , Script.Quest.QI106 , Script.Quest.QI184 , Script.Quest.QI186 , Script.Quest.QI187

def GetQuestReward():
  return Script.Quest.QR104 , Script.Quest.QR106 , Script.Quest.QR183 , Script.Quest.QR186 , Script.Quest.QR187


def Talk( player ):
# print "talk to Sparta_Newbie_008"
  return "Sparta_Newbie_008"

