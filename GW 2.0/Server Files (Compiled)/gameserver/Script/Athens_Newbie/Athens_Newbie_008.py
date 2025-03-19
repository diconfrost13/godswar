import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTGIVER+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)

def GetQuest():
  return Script.Quest.QI1013 , Script.Quest.QI1014 , Script.Quest.QI1188 , Script.Quest.QI1189 , Script.Quest.QI1213 , Script.Quest.QI1214 , Script.Quest.QI1215 , Script.Quest.QI1216

def GetQuestReward():
  return Script.Quest.QR1012 , Script.Quest.QR1013 , Script.Quest.QR1188 , Script.Quest.QR1189 , Script.Quest.QR1213 , Script.Quest.QR1214 , Script.Quest.QR1215 , Script.Quest.QR1216


def Talk( player ):
# print "talk to Athens_Newbie_008"
  return "Athens_Newbie_008"

