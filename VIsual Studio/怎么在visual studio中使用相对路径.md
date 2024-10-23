```python
from transformers import AutoConfig, WhisperForConditionalGeneration, AutoTokenizer, pipeline, AutoFeatureExtractor
#本地模型路径F:\Python\HuggingFace_models\openai\whisper-large-v2
#F:\Python\Transformers\pipeline的使用\pipeline的使用.py
model_path=R"..\..\HuggingFace_models\openai\whisper-large-v2"
#加载分词器
tokenizer = AutoTokenizer.from_pretrained(model_path)
#加载模型
model = WhisperForConditionalGeneration.from_pretrained(model_path)
feature_extractor = AutoFeatureExtractor.from_pretrained(model_path)
#加载pipeline,任务为自动语音识别
transcriber = pipeline(task="automatic-speech-recognition",model=model,tokenizer=tokenizer,feature_extractor=feature_extractor)
#识别本地音频文件
result=transcriber("./离别开出花.flac")
#打印识别结果
print(result)
```
![[visual studio中python相对路径的设置.png]]![[python相对路径的自动语音识别项目的结果.png]]