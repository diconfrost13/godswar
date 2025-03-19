import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI83 , Script.Quest.QI84 , Script.Quest.QI167 , Script.Quest.QI168

def GetQuestReward():
  return Script.Quest.QR82 , Script.Quest.QR83 , Script.Quest.QR139 , Script.Quest.QR167 , Script.Quest.QR168


def Talk( player ):
# print "talk to Argolis_All_002"
  return "Argolis_All_002"

