import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI13 , Script.Quest.QI14 , Script.Quest.QI188 , Script.Quest.QI189 , Script.Quest.QI213 , Script.Quest.QI214 , Script.Quest.QI215 , Script.Quest.QI216

def GetQuestReward():
  return Script.Quest.QR12 , Script.Quest.QR13 , Script.Quest.QR188 , Script.Quest.QR189 , Script.Quest.QR213 , Script.Quest.QR214 , Script.Quest.QR215 , Script.Quest.QR216


def Talk( player ):
# print "talk to Sparta_Newbie_004"
  return "Sparta_Newbie_004"

