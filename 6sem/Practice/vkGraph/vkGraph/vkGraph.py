import vk_api
import json

#login = input("login:")
#passw = input("pass:")

vk_session = vk_api.VkApi("dbmttblastik@yandex.ru", "ecoWoo14")
vk_session.auth()

vk = vk_session.get_api()

p = json.loads(vk.friends.get())

for x in p['response']:
    print('Ищем друзей юзера '+str(x['uid']))