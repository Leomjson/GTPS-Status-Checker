#pragma once
#include <xstring>
using namespace std;
#define newline  + '\n' +
using writerJS_C_ = basic_string<char, char_traits<char>, allocator<char>>;
#pragma warning(disable: 4996)

namespace JS
{
	namespace npm {
		void init();
		void install(const char* module_name);
	}
	namespace node {
		void run();
		void destroy();
	}

	writerJS_C_ require(writerJS_C_ m);

	namespace console {
		writerJS_C_ log(writerJS_C_ str);
		writerJS_C_ slog(writerJS_C_ str);
	}

	namespace fs
	{
		writerJS_C_ include();
		writerJS_C_ fs(writerJS_C_ file);
	}

	writerJS_C_ const_(writerJS_C_ str);
	writerJS_C_ setInterval(writerJS_C_ inside, uint64_t sleep_for);

	namespace child_process {
		writerJS_C_ include();
		writerJS_C_ process();
		writerJS_C_ check_process(writerJS_C_ process, writerJS_C_ running, writerJS_C_ not_running);
		writerJS_C_ not_running(writerJS_C_ inside);
	}

	namespace discordjs {
		extern bool GatewayIntentBits;
		extern bool EmbedBuilder;
		extern bool ActivityType;
		writerJS_C_ include();
		writerJS_C_ login(writerJS_C_ token);
		writerJS_C_ cache_channel(uint64_t id);
		namespace embed {
			extern writerJS_C_ o;
			writerJS_C_ setColor(uint64_t hex);
			writerJS_C_ setTitle(writerJS_C_ str);
			writerJS_C_ setURL(writerJS_C_ str);

			writerJS_C_ setAuthor(writerJS_C_ name, writerJS_C_ icon, writerJS_C_ url);
			writerJS_C_ setDescription(writerJS_C_ str);
			writerJS_C_ setThumbnail(writerJS_C_ str);
			writerJS_C_ setImage(writerJS_C_ str);
			writerJS_C_ setTimestamp();
			writerJS_C_ setFooter(writerJS_C_ name, writerJS_C_ icon);
			writerJS_C_ addFields(writerJS_C_ title, writerJS_C_ desc, bool inline_);

			writerJS_C_ send(writerJS_C_ channel, writerJS_C_ const_);
			namespace callback {
				writerJS_C_ send(writerJS_C_ channel, writerJS_C_ const_);
				writerJS_C_ cb(writerJS_C_ inside);
				writerJS_C_ edit(writerJS_C_ const_);
			}
		}
		namespace event {
			writerJS_C_ ready(writerJS_C_ inside);
		}
		namespace bot {
			namespace user {
				writerJS_C_ online();
				writerJS_C_ idle();
				writerJS_C_ dnd();
				writerJS_C_ invisible();
				writerJS_C_ setPresence(writerJS_C_ str, writerJS_C_ status = "online", writerJS_C_ type = "", writerJS_C_ twitch_username = "");
				writerJS_C_ tag();
			}
		}
	}

	void WriterJS(string it);
}