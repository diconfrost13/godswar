import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI7 , Script.Quest.QI12 , Script.Quest.QI145 , Script.Quest.QI146 , Script.Quest.QI147

def GetQuestReward():
  return Script.Quest.QR6 , Script.Quest.QR11 , Script.Quest.QR145 , Script.Quest.QR146 , Script.Quest.QR147


def Talk( player ):
# print "talk to Sparta_Newbie_003"
  return "Sparta_Newbie_003"

