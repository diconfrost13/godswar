import Script.Global
import Script.Item

if __name__ == '__main__':
  print ""

def GetType():
  return (Script.NPCConfig.NPC_FLAG_NONE+Script.NPCConfig.NPC_FLAG_QUESTRESPONDER)


def GetQuestReward():
  return Script.Quest.QR1210 , Script.Quest.QR1211 , Script.Quest.QR1212 , Script.Quest.QR1227 , Script.Quest.QR1228 , Script.Quest.QR1229 , Script.Quest.QR1230


def Talk( player ):
# print "talk to Athens_045"
  return "Athens_045"

