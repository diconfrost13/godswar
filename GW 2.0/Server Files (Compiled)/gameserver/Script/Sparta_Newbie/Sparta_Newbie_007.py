import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI141 , Script.Quest.QI142 , Script.Quest.QI143 , Script.Quest.QI144

def GetQuestReward():
  return Script.Quest.QR140 , Script.Quest.QR141 , Script.Quest.QR143 , Script.Quest.QR144


def Talk( player ):
# print "talk to Sparta_Newbie_007"
  return "Sparta_Newbie_007"

