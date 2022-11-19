#include "writerJS.hpp"
#pragma comment(lib, "WriterJS.lib")
using namespace std;
using namespace JS;

#define _ WriterJS

uint64_t channel_ID = 0; // channel id here
writerJS_C_ token = "token here";

int main()
{
	node::destroy();
	npm::init();
	npm::install("discord.js child_process");

	discordjs::GatewayIntentBits = true, discordjs::EmbedBuilder = true;
	_(discordjs::include());
	_(child_process::include());

	_(child_process::process());

	// in ready event
	_(discordjs::event::ready(
		console::slog(discordjs::bot::user::tag() + " is online!")newline
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
	while (true);
}