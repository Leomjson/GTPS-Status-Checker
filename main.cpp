#include "writerJS.hpp"
#include <iostream>
#pragma comment(lib, "WriterJS.lib")
#pragma comment(lib, "Ws2_32.lib") // WinSock
using namespace std; using namespace JS;
#define _ WriterJS

uint64_t channel_ID = 1043382141532250232; // channel id here
writerJS_C_ token = "MTA0MjY3NTQ3NDUxNTYyODA3NA.GMOjPA.58C8EEvtWOSIVqcmbl613S_6wSMCRcZozARxOc"; // bot token here

int main()
{
	node::destroy();
	npm::init();
	npm::install("discord.js child_process fs");
	discordjs::GatewayIntentBits = true, 
		discordjs::EmbedBuilder = true, 
		discordjs::ActivityType = true;
	_(discordjs::include());
	_(child_process::include());
	_(fs::include());
	_(child_process::process());

	_(discordjs::event::ready
	(
		console::slog(discordjs::bot::user::tag() + " is online!")newline

		discordjs::bot::user::setPresence("type whatever here!", discordjs::bot::user::online(), "streaming", "gtps7")newline

		const_("channel1") + discordjs::cache_channel(channel_ID)newline
		const_("embed1") + discordjs::embed::setTitle("Loading...")newline
		discordjs::embed::setColor(0xffb31e)newline
		discordjs::embed::callback::send("channel1", "embed1") + discordjs::embed::callback::cb
		(
			setInterval
			(
				child_process::check_process
				(
					"gtps7.exe",

					const_("embed2") + discordjs::embed::setTitle("GTPS7 is UP!")newline
					discordjs::embed::setColor(0xffb31e)newline
					discordjs::embed::setImage("https://cdn.discordapp.com/attachments/1043382141532250232/1043418272042848256/0987e31b8dabba135ccea1834a745e8a.png")newline
					discordjs::embed::setTimestamp()newline
					discordjs::embed::callback::edit("embed2"),

					const_("embed3") + discordjs::embed::setTitle("GTPS7 is DOWN!")newline
					discordjs::embed::setColor(0xffb31e)newline
					discordjs::embed::setImage("https://cdn.discordapp.com/attachments/1043382141532250232/1043418272042848256/0987e31b8dabba135ccea1834a745e8a.png")newline
					discordjs::embed::setTimestamp()newline
					discordjs::embed::callback::edit("embed3")
				),
				12000
			)
		)
	));
	_(discordjs::login(token));
	node::run();
	cout << "test" << endl;
	while (true);
}
