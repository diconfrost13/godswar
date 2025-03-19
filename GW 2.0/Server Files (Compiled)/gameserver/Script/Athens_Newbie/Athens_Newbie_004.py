import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1005 , Script.Quest.QI1006 , Script.Quest.QI1036 , Script.Quest.QI1038

def GetQuestReward():
  return Script.Quest.QR1004 , Script.Quest.QR1005 , Script.Quest.QR1035 , Script.Quest.QR1037


def Talk( player ):
# print "talk to Athens_Newbie_004"
  return "Athens_Newbie_004"

